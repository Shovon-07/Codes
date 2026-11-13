const api = `http://127.0.0.1:8080`;

const names = [
  "main-gate",        // 0
  "gate-2",           // 1
  "gate-3",           // 2
  "bus-stand",        // 3
  "play-ground-1",    // 4
  "play-ground-2",    // 5
  "garden",           // 6
  "canteen",          // 7
  "mid-corridor",     // 8
  "library",          // 9
  "gate-tl",          // 10
  "info-desk",        // 11
  "boys-common",      // 12
  "mosque",           // 13
  "pharmacy",         // 14
  "plaza",            // 15
  "sinat",            // 16
  "inventory",        // 17
  "auditorium",       // 18
  "eee-lab",          // 19
  "girls-common",     // 20
  "cr-center",        // 21
  "american-corner",  // 22
  "ncc-bank",         // 23
  "cse-faculty",      // 24
  "bba-dept",         // 25
  "eee-office",       // 26
  "lift",             // 27
  "cse-office",       // 28
  "parking",          // 29
  "medical",          // 30
  "gate-tr",          // 31
  "gate-br",          // 32
  "stair",            // 33
  "junc-main",        // 34
  "junc-tl",          // 35
  "junc-tr",          // 36
  "junc-se"           // 37
];

let fetchedLocations = {};

function highlightPath(path, distance, reachable) {
  document.querySelectorAll("[id^='node-']").forEach((node) => {
    node.style.fill = node.classList.contains("junction") ? "#64748b" : "#2563eb";
  });

  document.querySelectorAll("[id^='edge-']").forEach((edge) => {
    edge.style.stroke = "#9499a4";
    edge.style.strokeWidth = "2.8";
  });

  if (!reachable || path.length === 0) {
    document.getElementById("distanceMonitor").innerHTML = "No route (One-way)";
    document.getElementById("distanceMonitor").style.color = "#dc2626";
    return;
  }

  document.getElementById("distanceMonitor").style.color = "#00ab13";

  path.forEach((v, idx) => {
    const node = document.getElementById("node-" + names[v]);
    if (node) {
      if (idx === 0) {
        node.style.fill = "#f59e0b"; // Source
      } else if (idx === path.length - 1) {
        node.style.fill = "#ef4444"; // Destination
      } else {
        node.style.fill = "#22c55e"; // Intermediate
      }
    }
  });

  for (let i = 0; i < path.length - 1; i++) {
    const u = path[i];
    const v = path[i + 1];

    const forward = document.getElementById(`edge-${u}-${v}`);
    const backward = document.getElementById(`edge-${v}-${u}`);
    const edge = forward || backward;
    if (!edge) continue;

    edge.style.stroke = "#16a34a";
    edge.style.strokeWidth = "4.5";
  }

  document.getElementById("distanceMonitor").innerHTML = distance + " m";
}

async function loadLocations() {
  const source = document.getElementById("source");
  const destination = document.getElementById("destination");

  try {
    const response = await fetch(`${api}/locations`);
    if (!response.ok) throw new Error("Failed");

    const data = await response.json();
    source.replaceChildren();
    destination.replaceChildren();

    const sDef = document.createElement("option");
    sDef.value = "-1";
    sDef.textContent = "Source";
    source.appendChild(sDef);

    const dDef = document.createElement("option");
    dDef.value = "-1";
    dDef.textContent = "Destination";
    destination.appendChild(dDef);

    data.locations.forEach((loc) => {
      fetchedLocations[loc.id] = loc.name;

      const opt1 = document.createElement("option");
      opt1.value = loc.id;
      opt1.textContent = loc.name;
      source.appendChild(opt1);

      const opt2 = document.createElement("option");
      opt2.value = loc.id;
      opt2.textContent = loc.name;
      destination.appendChild(opt2);
    });
  } catch (error) {
    console.error("Error loading locations:", error);
  }
}

const findPath = async () => {
  const source = Number(document.getElementById("source").value);
  const destination = Number(document.getElementById("destination").value);

  if (source >= 0 && destination >= 0 && source === destination) {
    highlightPath([source], 0, true);
    return;
  }

  if (source >= 0 && destination >= 0) {
    try {
      const response = await fetch(`${api}/find-path`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ source, destination }),
      });

      if (!response.ok) throw new Error("Backend request failed");

      const data = await response.json();
      highlightPath(data.path, data.distance, data.reachable);
    } catch (error) {
      console.error(error);
      alert("Backend server is not running (start the C++ server first).");
    }
  } else {
    alert("Please enter source & destination");
  }
};

const search = () => {
  const input = document.getElementById("searchInput").value.trim();
  const searchList = document.getElementById("searchList");
  searchList.innerHTML = "";

  const entries = Object.values(fetchedLocations);
  const filtered =
    input === ""
      ? entries
      : entries.filter((item) =>
          item.toLowerCase().includes(input.toLowerCase())
        );

  filtered.forEach((item) => {
    const li = document.createElement("li");
    li.textContent = item;
    searchList.appendChild(li);
  });
};

window.addEventListener("load", async () => {
  await loadLocations();
  search();
  document.getElementById("searchInput").addEventListener("input", search);
});