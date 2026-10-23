const names = [
  "main-gate",
  "gate-2",
  "gate-3",
  "bus-stand",
  "library",
  "cafeteria",
  "cse-office",
  "auditorium",
];

function highlightPath(path) {
  // সব vertex-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='node-']").forEach((node) => {
    node.style.fill = "#2563eb";
  });

  // সব edge-এর আগের highlight মুছে ফেলো
  document.querySelectorAll("[id^='edge-']").forEach((edge) => {
    edge.style.stroke = "gray";
    edge.style.strokeWidth = "5";
  });

  // Shortest path-এর vertex highlight
  path.forEach((v) => {
    const node = document.getElementById("node-" + names[v]);

    if (node) node.style.fill = "orange";
  });

  // Shortest path-এর edge highlight
  for (let i = 0; i < path.length - 1; i++) {
    let u = names[path[i]];
    let v = names[path[i + 1]];
    // let u = path[i];
    // let v = path[i + 1];

    // Undirected edge-এর জন্য ID একই রাখো
    let edgeId = [u, v].sort().join("-");

    const edge = document.getElementById("edge-" + edgeId);

    if (edge) {
      edge.style.stroke = "red";
      edge.style.strokeWidth = "8";
    }
  }
}

// highlightPath([0, 2, 3]);
