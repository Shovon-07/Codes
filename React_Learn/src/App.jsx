import { useState } from "react";

/* Import css */
import "./App.css";
import "./assets/css/style.css";
import "./assets/css/sass.css";
import "./assets/css/bootstrap_css/bootstrap.min.css";

/* Import Component */
import Header from "./Components/Header";
import Hero from "./Components/Hero";

import ClassComponent from "./Components/ClassComponent/ClassComponent";
import FunctionalComponent from "./Components/FunctionalComponent/FunctionalComponent";

import ClickCounter from "./Components/React_js_systax/HigherOrderComponent_HOC/ClickCounter";
import HoverCounter from "./Components/React_js_systax/HigherOrderComponent_HOC/HoverCounter";

import Statements from "./Components/React_js_systax/Statements";
import Hook from "./Components/React_js_systax/Hook";
import NestedComponent from "./Components/React_js_systax/NestedComponent";

import Contact from "./Components/Contact";
import Footer from "./Components/Footer";

function App() {
  return (
    <>
      <Header />
      <Hero />

      <ClassComponent />

      <br />
      <br />

      <FunctionalComponent />

      <br />
      <br />

      <br />
      <br />

      <ClickCounter />
      <HoverCounter />

      <br />
      <br />

      <Statements />
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
