import React from "react";
import ClockInClassComponent from "./ClassComponent/ClockInClassComponent";
import ClockInFunctionalComponent from "./FunctionalComponent/ClockInFunctionalComponent";

// Routing
import { NavLink } from "react-router-dom";

const Header = () => {
  return (
    <>
      <div className="sticky-top">
        <div style={{ color: "green", background: "#000", padding: "15px" }}>
          <h1 className="text-center">Learn React</h1>
        </div>

        <div className="headerNav px-4">
          {/* <ClockInClassComponent /> */}
          <ClockInFunctionalComponent />
          {/* <ul>
            <li>
              <a href="/">Home</a>
            </li>
            <li>
              <a href="/about">About</a>
            </li>
            <li>
              <a href="">Services</a>
            </li>
            <li>
              <a href="">Projects</a>
            </li>
            <li>
              <a href="">Contact</a>
            </li>
          </ul> */}

          <ul>
            <li>
              <NavLink to={"/"}>Home</NavLink>
            </li>
            <li>
              <NavLink to={"/about"}>About</NavLink>
            </li>
            <li>
              <NavLink to={"/services"}>Services</NavLink>
            </li>
            <li>
              <NavLink to={"/projects"}>Projects</NavLink>
            </li>
            <li>
              <NavLink to={"/contact"}>Contact</NavLink>
            </li>
          </ul>
        </div>
      </div>
    </>
  );
};

export default Header;
