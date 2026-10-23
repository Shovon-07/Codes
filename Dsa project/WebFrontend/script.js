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
];

function highlightPath(path) {
  // সব vertex-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='node-']").forEach((node) => {
    node.style.fill = "#2563eb";
  });

  // সব edge-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='edge-']").forEach((edge) => {
    edge.style.stroke = "#6a6e77";
    // edge.style.strokeWidth = "5";
  });

  // Shortest path-এর vertex highlight
  path.forEach((v) => {
    const node = document.getElementById("node-" + names[v]);
    if (node) node.style.fill = "orange";
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

highlightPath([2, 0, 3]);
