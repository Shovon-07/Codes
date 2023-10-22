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

import Contact from "./Components/Contact";
import Footer from "./Components/Footer";

// Routing
// import { Navigate, Route, Routes } from "react-router-dom";
import { Routes, Route } from "react-router-dom";

import Home from "./Pages/Home";
import About from "./Pages/About";
import Services from "./Pages/Services";
import Projects from "./Pages/Projects";
import NotFoundPage from "./Pages/NotFoundPage";

function App() {
  return (
    <>
      {/* Routing */}
      {/* <Router>
        <Header />

        <Switch>
          <Route exact path="/" Component={Home} />
          <Route exact path="/about" Component={About} />
        </Switch>
      </Router> */}

      <Routes>
        <Route path="/" element={<Home />} />
        <Route path="/about" element={<About />} />
        <Route path="/services" element={<Services />} />
        <Route path="/Projects" element={<Projects />} />
        <Route path="*" element={<NotFoundPage />} />

        {/* Pass parameter/Id */}
        <Route path="/MyPage/:id" element={<Mypage />} />
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

      <Contact />

      <NestedComponent>
        <Header />
      </NestedComponent>

      <Footer />
    </>
  );
}

export default App;
