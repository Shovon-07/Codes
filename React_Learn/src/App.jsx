import { useEffect, useState } from "react";

/* Import css */
import "./App.css";
import "./assets/css/style.css";
import "./assets/css/sass.css";
import "./assets/css/bootstrap_css/bootstrap.min.css";

/* Import Component */
import Header from "./Components/Header";

import ClassComponent from "./Components/ClassComponent/ClassComponent";
import FunctionalComponent from "./Components/FunctionalComponent/FunctionalComponent";

import ClickCounter_HOC from "./Components/React_js_systax/HigherOrderComponent_HOC/ClickCounter_HOC";
import HoverCounter_HOC from "./Components/React_js_systax/HigherOrderComponent_HOC/HoverCounter_HOC";

// import Statements from "./Components/React_js_systax/Statements";
import RenderProps from "./Components/React_js_systax/RenderProps";
import Hook from "./Components/React_js_systax/Hook";
import NestedComponent from "./Components/React_js_systax/NestedComponent";

import Footer from "./Components/Footer";

/* Routing */
import { Routes, Route, Navigate } from "react-router-dom";

import Home from "./Pages/Home";
import About from "./Pages/About";
import Services from "./Pages/Services";
import Projects from "./Pages/Projects";
import Contact from "./Pages/Contact";
import NestedRoute from "./Pages/NestedRoute";
import NotFoundPage from "./Pages/NotFoundPage";

function App() {
  return (
    <>
      <Header />
      {/* Routing */}
      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />} />
        <Route path="/services" element={<Services />} />
        <Route path="/projects" element={<Projects />} />
        <Route path="/contact" element={<Contact />} />

        {/* Redirect any other path */}
        <Route path="/redirect" element={<Navigate to="/contact" />} />

        {/* Nested Route */}
        <Route path="/nestedRoute/*" element={<NestedRoute />}>
          <Route path="nestedRouteChild" element={<Contact />} />
        </Route>

        <Route path="/*" element={<NotFoundPage />} />
      </Routes>

      {/* <Header /> */}

      {/* <Hero /> */}

      <hr />
      <ClassComponent />
      <hr />

      <br />
      <br />

      <hr />
      <FunctionalComponent />
      <hr />

      {/* Higher Oreder Component */}
      <ClickCounter_HOC />
      <HoverCounter_HOC />

      <br />
      <br />

      {/* React Syntax */}
      {/* <Statements /> */}

      <br />
      <br />

      {/* Render Props */}
      <RenderProps render={(isLoggedIn) => (isLoggedIn ? "Shovon" : "User")} />

      <br />
      <br />

      <Hook />

      <NestedComponent>
        <Header />
      </NestedComponent>

      <Footer />
    </>
  );
}

export default App;
