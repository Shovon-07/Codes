// const api = `https://dsa-project-sa2h.onrender.com`;
const api = `http://127.0.0.1:8080`;
const names = [
  "main-gate",
  "gate-2",
  "gate-3",
  "bus-stand",
  "ground-1",
  "ground-2",
  "garden",
  "cafeteria",
  "parking",
  "flower-garder",
];
let fetchedLocations = {};

function highlightPath(path) {
  // সব vertex-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='node-']").forEach((node) => {
    node.style.fill = "#2563eb";
  });

  // সব edge-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='edge-']").forEach((edge) => {
    edge.style.stroke = "#9499a4";
    // edge.style.strokeWidth = "5";
  });

  // Shortest path-এর vertex highlight
  path.forEach((v) => {
    const node = document.getElementById("node-" + names[v]);
    if (node) node.style.fill = "#69f957";
  });

  // Shortest path-এর edge highlight
  for (let i = 0; i < path.length - 1; i++) {
    let u = path[i];
    let v = path[i + 1];

    // Undirected edge-এর জন্য numeric ID
    let edgeId = `edge-${Math.min(u, v)}-${Math.max(u, v)}`;
    const edge = document.getElementById(edgeId);

    if (edge) {
      edge.style.stroke = "#242629";
      edge.style.strokeWidth = "5";
      // edge.style.filter = "drop-shadow(2px 3px 3px rgba(4, 255, 0, 0.93))";
    }
  }
  console.log("Route founded");
}

//=>>> Work with api
async function loadLocations() {
  const source = document.getElementById("source");
  const destination = document.getElementById("destination");

  try {
    const response = await fetch(`${api}/locations`);

    if (!response.ok) {
      throw new Error("Failed to load locations");
    }

    const data = await response.json();

    // পুরোনো options মুছে ফেলো
    source.replaceChildren();
    destination.replaceChildren();

    // দুইটি select-এর জন্য আলাদা default option
    const sourceDefault = document.createElement("option");
    sourceDefault.value = "-1";
    sourceDefault.textContent = "Select source";

    const destinationDefault = document.createElement("option");
    destinationDefault.value = "-1";
    destinationDefault.textContent = "Select destination";

    source.appendChild(sourceDefault);
    destination.appendChild(destinationDefault);

    // C++ backend থেকে locations নিয়ে options তৈরি
    data.locations.forEach((location) => {
      fetchedLocations[location.id] = location.name;
      // Source-এর option
      const sourceOption = document.createElement("option");
      sourceOption.value = location.id;
      sourceOption.textContent = location.name;
      source.appendChild(sourceOption);

      // Destination-এর option
      const destinationOption = document.createElement("option");
      destinationOption.value = location.id;
      destinationOption.textContent = location.name;
      destination.appendChild(destinationOption);
    });
  } catch (error) {
    console.error("Error loading locations:", error);

    source.replaceChildren();
    destination.replaceChildren();

    const sourceError = document.createElement("option");
    sourceError.value = "-1";
    sourceError.textContent = "Failed to load locations";

    const destinationError = document.createElement("option");
    destinationError.value = "-1";
    destinationError.textContent = "Failed to load locations";

    source.appendChild(sourceError);
    destination.appendChild(destinationError);
  }
}

const findPath = async () => {
  const source = Number(document.getElementById("source").value);
  const destination = Number(document.getElementById("destination").value);
  console.log(source);
  console.log(destination);

  if (source >= 0 && destination >= 0) {
    try {
      const response = await fetch(`${api}/find-path`, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ source, destination }),
      });

      if (!response.ok) {
        throw new Error("Backend request failed");
      }

      const data = await response.json();
      console.log(data.path);
      highlightPath(data.path);

      // document.getElementById("result").textContent =
      //     "Result: " + data.result;
    } catch (error) {
      // document.getElementById("result").textContent =
      //     "Backend-এর সঙ্গে সংযোগ করা যায়নি।";
      console.error(error);
    }
  } else {
    alert("Please enter source & destination");
  }
};

//=>>> searching
const search = () => {
  const input = document.getElementById("searchInput").value.trim();
  const searchList = document.getElementById("searchList");

  // Clear previous search results so they don't stack up
  searchList.innerHTML = "";

  // Filter the values and create an <li> for each match
  input == ""
    ? ""
    : Object.values(fetchedLocations)
        .filter((item) => item.toLowerCase().includes(input.toLowerCase()))
        .forEach((item) => {
          const createSearchList = document.createElement("li");
          createSearchList.textContent = item; // Sets the text to the matching item
          searchList.appendChild(createSearchList);
        });
};

window.addEventListener("load", async () => {
  await loadLocations();

  const searchList = document.getElementById("searchList");
  searchList.innerHTML = "";
  Object.values(fetchedLocations).forEach((item) => {
    const createSearchList = document.createElement("li");
    createSearchList.textContent = item; // Sets the text to the matching item
    searchList.appendChild(createSearchList);
  });
});
