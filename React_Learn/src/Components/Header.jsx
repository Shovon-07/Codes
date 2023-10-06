import React from "react";
import Clock from "./Clock";
import "../assets/Images/robot.jpeg";

const Header = () => {
  return (
    <>
      <h1
        className="text-center"
        style={{
          color: "green",
          background: "#000",
          padding: "15px",
        }}
      >
        <p>Learn React</p>
        <p></p>
      </h1>

      <div className="headerNav">
        <Clock />
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
    </>
  );
};

export default Header;
