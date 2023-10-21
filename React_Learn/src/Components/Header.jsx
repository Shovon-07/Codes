import React from "react";
import ClockInClassComponent from "./ClassComponent/ClockInClassComponent";
import ClockInFunctionalComponent from "./FunctionalComponent/ClockInFunctionalComponent";

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
          <ul>
            <li>
              <a href="">Home</a>
            </li>
            <li>
              <a href="">About</a>
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
          </ul>
        </div>
      </div>
    </>
  );
};

export default Header;
