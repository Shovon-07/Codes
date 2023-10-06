import { useState } from "react";

/* Import css */
import "./App.css";
import "./assets/css/style.css";
import "./assets/css/sass.css";
import "./assets/css/bootstrap_css/bootstrap.min.css";
import "./assets/css/font_awesome/all.min.css";
import "./assets/css/font_awesome/fontawesome.min.css";

/* Import Component */
import Header from "./Components/Header";
import Hero from "./Components/Hero";

import Statements from "./Components/React_js_systax/Statements";
import Props from "./Components/React_js_systax/Props";
import Hook from "./Components/React_js_systax/Hook";
import MyComponent from "./Components/React_js_systax/MyComponent";
import NestedComponent from "./Components/React_js_systax/NestedComponent";

import Contact from "./Components/Contact";
import Footer from "./Components/Footer";

function App() {
  const PropsObject = {
    name: "shovon",
    age: 20,
  };

  const PropsFunction = () => {
    alert("This is props function");
  };

  return (
    <>
      <Header />
      <Hero />
      <Statements />
      <Props
        title="This is react props."
        description="React props means react proparties."
        Object={PropsObject}
        Function={PropsFunction}
      />
      <Hook />
      <MyComponent msg="Use props" />
      <Contact />
      <Footer />

      <NestedComponent>
        <Header />
      </NestedComponent>
    </>
  );
}

export default App;
