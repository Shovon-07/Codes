// const api = `https://dsa-project-sa2h.onrender.com`;
const BASE_API = `http://127.0.0.1:8080`;

let currentTab = "favorites";

document.addEventListener("DOMContentLoaded", () => {
  fetchWishlist(currentTab);
});

// Switch tabs & fetch from backend
function switchTab(tab) {
  currentTab = tab;
  document
    .querySelectorAll(".wishList .list button")
    .forEach((btn) => btn.classList.remove("selected"));
  document.getElementById(`btn-${tab}`).classList.add("selected");

  const titles = {
    favorites: "Favorites",
    saved: "Saved Places",
    want: "Want to Go",
  };
  document.getElementById("wishlistTitle").innerText = titles[tab];

  fetchWishlist(tab);
}

// GET API call to fetch wishlist items from C++ backend
async function fetchWishlist(tab) {
  try {
    const response = await fetch(`${BASE_API}/wishlist?tab=${tab}`);
    const data = await response.json();
    renderWishlist(data.items);
  } catch (error) {
    console.error("Failed to fetch wishlist:", error);
  }
}

// Render items into the DOM list
function renderWishlist(items) {
  const container = document.getElementById("wishlistContainer");
  container.innerHTML = "";

  if (!items || items.length === 0) {
    container.innerHTML = `<li style="color: #64748b; font-style: italic; border:none; background:transparent;">No items added yet.</li>`;
    return;
  }

  items.forEach((item, index) => {
    const li = document.createElement("li");
    li.style.display = "flex";
    li.style.justifyContent = "space-between";
    li.style.alignItems = "center";

    li.innerHTML = `
            <span>${item}</span>
            <i class="fa-solid fa-trash" style="color: #ef4444; cursor: pointer; font-size: 0.8rem;" onclick="deleteWishlistItem(${index})" title="Remove"></i>
        `;
    container.appendChild(li);
  });
}

// POST API call to save currently selected dropdown route
async function saveCurrentRoute() {
  const sourceSelect = document.getElementById("source");
  const destSelect = document.getElementById("destination");

  if (!sourceSelect || !destSelect) return;

  if (sourceSelect.value === "-1" || destSelect.value === "-1") {
    alert("Please select both Source and Destination first!");
    return;
  }

  const sourceText = sourceSelect.options[sourceSelect.selectedIndex].text;
  const destText = destSelect.options[destSelect.selectedIndex].text;
  const routeString = `${sourceText} -> ${destText}`;

  try {
    const response = await fetch(`${BASE_API}/wishlist`, {
      method: "POST",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ tab: currentTab, item: routeString }),
    });

    if (response.ok) {
      fetchWishlist(currentTab);
    }
  } catch (error) {
    console.error("Failed to save route:", error);
  }
}

// POST API call for custom prompt item
async function promptAddItem(tab) {
  // const customName = prompt("Enter location or route (e.g., Mosque -> Library):");
  // if (!customName || customName.trim() === "") return;
  // try {
  //     const response = await fetch(`${BASE_API}/wishlist`, {
  //         method: 'POST',
  //         headers: { 'Content-Type': 'application/json' },
  //         body: JSON.stringify({ tab: tab, item: customName.trim() })
  //     });
  //     if (response.ok) {
  //         if (currentTab === tab) {
  //             fetchWishlist(currentTab);
  //         }
  //     }
  // } catch (error) {
  //     console.error("Failed to add item:", error);
  // }
}

// DELETE API call to remove an item from the backend
async function deleteWishlistItem(index) {
  try {
    const response = await fetch(`${BASE_API}/wishlist`, {
      method: "DELETE",
      headers: { "Content-Type": "application/json" },
      body: JSON.stringify({ tab: currentTab, index: index }),
    });

    if (response.ok) {
      fetchWishlist(currentTab);
    }
  } catch (error) {
    console.error("Failed to delete item:", error);
  }
}
