const svg = document.getElementById("campusMap");
const mapContent = document.getElementById("mapContent");

const zoomInBtn = document.getElementById("zoomIn");
const zoomOutBtn = document.getElementById("zoomOut");
const resetBtn = document.getElementById("resetMap");

let scale = 1;
let x = 0;
let y = 0;

const MIN_ZOOM = 0.5;
const MAX_ZOOM = 4;
const ZOOM_STEP = 1.2;

function updateMap() {
  mapContent.setAttribute("transform", `translate(${x} ${y}) scale(${scale})`);
}

// Convert screen coordinates to SVG coordinates
function getSvgPoint(event) {
  const point = svg.createSVGPoint();

  point.x = event.clientX;
  point.y = event.clientY;

  return point.matrixTransform(svg.getScreenCTM().inverse());
}

// Zoom around a specific SVG point
function zoomAt(newScale, px, py) {
  newScale = Math.max(MIN_ZOOM, Math.min(MAX_ZOOM, newScale));

  const ratio = newScale / scale;

  x = px - (px - x) * ratio;
  y = py - (py - y) * ratio;

  scale = newScale;

  updateMap();
}

// Zoom buttons
zoomInBtn.addEventListener("click", () => {
  const rect = svg.getBoundingClientRect();

  const center = getSvgPoint({
    clientX: rect.left + rect.width / 2,
    clientY: rect.top + rect.height / 2,
  });

  zoomAt(scale * ZOOM_STEP, center.x, center.y);
});

zoomOutBtn.addEventListener("click", () => {
  const rect = svg.getBoundingClientRect();

  const center = getSvgPoint({
    clientX: rect.left + rect.width / 2,
    clientY: rect.top + rect.height / 2,
  });

  zoomAt(scale / ZOOM_STEP, center.x, center.y);
});

// Reset map
resetBtn.addEventListener("click", () => {
  scale = 1;
  x = 0;
  y = 0;

  updateMap();
});

// Mouse wheel zoom
svg.addEventListener(
  "wheel",
  (event) => {
    event.preventDefault();

    const point = getSvgPoint(event);

    const factor = event.deltaY < 0 ? ZOOM_STEP : 1 / ZOOM_STEP;

    zoomAt(scale * factor, point.x, point.y);
  },
  { passive: false },
);

// =================================
// Mouse & Touch Pan / Pinch Zoom
// =================================

const pointers = new Map();

let lastPoint = null;
let pinchStartDistance = 0;
let pinchStartScale = 1;
let pinchMapPoint = null;

// Calculate distance between two fingers
function getDistance(p1, p2) {
  return Math.hypot(p2.x - p1.x, p2.y - p1.y);
}

// Get midpoint between two fingers
function getMidpoint(p1, p2) {
  return {
    x: (p1.x + p2.x) / 2,
    y: (p1.y + p2.y) / 2,
  };
}

// Pointer down
svg.addEventListener("pointerdown", (event) => {
  if (event.target.closest("button, a")) return;

  event.preventDefault();

  svg.setPointerCapture(event.pointerId);

  const point = getSvgPoint(event);

  pointers.set(event.pointerId, point);

  // One finger / mouse drag
  if (pointers.size === 1) {
    lastPoint = point;
  }

  // Two fingers / pinch zoom
  if (pointers.size === 2) {
    const [p1, p2] = [...pointers.values()];

    pinchStartDistance = getDistance(p1, p2);
    pinchStartScale = scale;

    const midpoint = getMidpoint(p1, p2);

    // Map position under the midpoint
    pinchMapPoint = {
      x: (midpoint.x - x) / scale,
      y: (midpoint.y - y) / scale,
    };

    lastPoint = null;
  }

  svg.classList.add("dragging");
});

// Pointer move
svg.addEventListener("pointermove", (event) => {
  if (!pointers.has(event.pointerId)) return;

  event.preventDefault();

  const point = getSvgPoint(event);

  pointers.set(event.pointerId, point);

  // One finger / mouse pan
  if (pointers.size === 1) {
    if (!lastPoint) {
      lastPoint = point;
      return;
    }

    x += point.x - lastPoint.x;
    y += point.y - lastPoint.y;

    lastPoint = point;

    updateMap();
  }

  // Two finger pinch zoom
  else if (pointers.size === 2) {
    const [p1, p2] = [...pointers.values()];

    const currentDistance = getDistance(p1, p2);

    if (pinchStartDistance === 0) return;

    let newScale = pinchStartScale * (currentDistance / pinchStartDistance);

    newScale = Math.max(MIN_ZOOM, Math.min(MAX_ZOOM, newScale));

    const midpoint = getMidpoint(p1, p2);

    // Keep the map position under fingers fixed
    scale = newScale;

    x = midpoint.x - pinchMapPoint.x * scale;
    y = midpoint.y - pinchMapPoint.y * scale;

    updateMap();
  }
});

// Pointer up / cancel
function stopDragging(event) {
  pointers.delete(event.pointerId);

  if (pointers.size === 1) {
    // Continue dragging with remaining finger
    lastPoint = [...pointers.values()][0];
  } else {
    lastPoint = null;
    pinchStartDistance = 0;
    pinchMapPoint = null;
  }

  if (pointers.size === 0) {
    svg.classList.remove("dragging");
  }
}

svg.addEventListener("pointerup", stopDragging);
svg.addEventListener("pointercancel", stopDragging);
svg.addEventListener("lostpointercapture", stopDragging);

// Initial map
updateMap();

// const svg = document.getElementById("campusMap");
// const mapContent = document.getElementById("mapContent");

// const zoomInBtn = document.getElementById("zoomIn");
// const zoomOutBtn = document.getElementById("zoomOut");
// const resetBtn = document.getElementById("resetMap");

// let scale = 1;
// let x = 0;
// let y = 0;

// const MIN_ZOOM = 0.5;
// const MAX_ZOOM = 4;
// const ZOOM_STEP = 1.2;

// function updateMap() {
//   mapContent.setAttribute("transform", `translate(${x} ${y}) scale(${scale})`);
// }

// function getSvgPoint(event) {
//   const point = svg.createSVGPoint();

//   point.x = event.clientX;
//   point.y = event.clientY;

//   return point.matrixTransform(svg.getScreenCTM().inverse());
// }

// // নির্দিষ্ট SVG position-কে কেন্দ্র করে zoom
// function zoomAt(newScale, px, py) {
//   newScale = Math.max(MIN_ZOOM, Math.min(MAX_ZOOM, newScale));

//   // Zoom-এর সময় pointer-এর নিচের জায়গা স্থির রাখে
//   x = px - (px - x) * (newScale / scale);
//   y = py - (py - y) * (newScale / scale);

//   scale = newScale;
//   updateMap();
// }

// // Zoom In
// zoomInBtn.addEventListener("click", () => {
//   zoomAt(scale * ZOOM_STEP, 400, 250);
// });

// // Zoom Out
// zoomOutBtn.addEventListener("click", () => {
//   zoomAt(scale / ZOOM_STEP, 400, 250);
// });

// // Reset
// resetBtn.addEventListener("click", () => {
//   scale = 1;
//   x = 0;
//   y = 0;
//   updateMap();
// });

// // Mouse wheel zoom
// svg.addEventListener(
//   "wheel",
//   (event) => {
//     event.preventDefault();

//     const point = getSvgPoint(event);

//     const factor = event.deltaY < 0 ? ZOOM_STEP : 1 / ZOOM_STEP;

//     zoomAt(scale * factor, point.x, point.y);
//   },
//   { passive: false },
// );

// // Drag / Pan
// let dragging = false;
// let lastPoint = null;

// svg.addEventListener("pointerdown", (event) => {
//   // Button বা অন্য interactive element থেকে drag শুরু নয়
//   if (event.target.closest("button, a")) return;

//   dragging = true;
//   lastPoint = getSvgPoint(event);

//   svg.setPointerCapture(event.pointerId);
//   svg.classList.add("dragging");
// });

// svg.addEventListener("pointermove", (event) => {
//   if (!dragging) return;

//   const point = getSvgPoint(event);

//   x += point.x - lastPoint.x;
//   y += point.y - lastPoint.y;

//   lastPoint = point;
//   updateMap();
// });

// function stopDragging() {
//   dragging = false;
//   lastPoint = null;
//   svg.classList.remove("dragging");
// }

// svg.addEventListener("pointerup", stopDragging);
// svg.addEventListener("pointercancel", stopDragging);

// // প্রথম অবস্থায় map দেখাও
// updateMap();
