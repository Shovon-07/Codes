import React from "react";
import "../assets/Images/hacker-face.jpg";
import Header from "../Components/Header";

const Home = () => {
  return (
    <>
      <div className="hero">
        {/* Bootstrap & Inline Css */}
        {/* <h1 className="text-center" style={{ color: "var(--off-white)" }}>
          This is Hero section
        </h1> */}
        <div className="heroTxt">
          <h1 className="mb-4">Al JUbair Shovon</h1>
          <p className="description">
            - Study in CSE(Computer Science & Engneering) at BPI. <br />- My
            Skills : Front end Development, Back end Development, Graphic
            designe etc. <br />- Currently I'm work in Fiverr marketplace &
            Linkedin.
          </p>
        </div>
      </div>
    </>
  );
};

export default Home;
