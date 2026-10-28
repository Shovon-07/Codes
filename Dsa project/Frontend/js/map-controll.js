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

function getSvgPoint(event) {
  const point = svg.createSVGPoint();

  point.x = event.clientX;
  point.y = event.clientY;

  return point.matrixTransform(svg.getScreenCTM().inverse());
}

// নির্দিষ্ট SVG position-কে কেন্দ্র করে zoom
function zoomAt(newScale, px, py) {
  newScale = Math.max(MIN_ZOOM, Math.min(MAX_ZOOM, newScale));

  // Zoom-এর সময় pointer-এর নিচের জায়গা স্থির রাখে
  x = px - (px - x) * (newScale / scale);
  y = py - (py - y) * (newScale / scale);

  scale = newScale;
  updateMap();
}

// Zoom In
zoomInBtn.addEventListener("click", () => {
  zoomAt(scale * ZOOM_STEP, 400, 250);
});

// Zoom Out
zoomOutBtn.addEventListener("click", () => {
  zoomAt(scale / ZOOM_STEP, 400, 250);
});

// Reset
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

// Drag / Pan
let dragging = false;
let lastPoint = null;

svg.addEventListener("pointerdown", (event) => {
  // Button বা অন্য interactive element থেকে drag শুরু নয়
  if (event.target.closest("button, a")) return;

  dragging = true;
  lastPoint = getSvgPoint(event);

  svg.setPointerCapture(event.pointerId);
  svg.classList.add("dragging");
});

svg.addEventListener("pointermove", (event) => {
  if (!dragging) return;

  const point = getSvgPoint(event);

  x += point.x - lastPoint.x;
  y += point.y - lastPoint.y;

  lastPoint = point;
  updateMap();
});

function stopDragging() {
  dragging = false;
  lastPoint = null;
  svg.classList.remove("dragging");
}

svg.addEventListener("pointerup", stopDragging);
svg.addEventListener("pointercancel", stopDragging);

// প্রথম অবস্থায় map দেখাও
updateMap();
