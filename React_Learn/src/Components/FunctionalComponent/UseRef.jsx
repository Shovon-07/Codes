import React, { useEffect, useRef } from "react";

const FunctionalUseRef = () => {
  // Change Dom text
  let txt = useRef();
  const ChangeTxt = () => {
    txt.current.style.color = "green";
    txt.current.innerHTML = "Text Changed using useRef function";
  };

  // Add Css Class
  let addClassDom = useRef();
  const addClass = () => {
    addClassDom.current.classList.add("addCssDom");
  };
  const removeClass = () => {
    addClassDom.current.classList.remove("addCssDom");
  };

  // Get input value
  let name,
    email = useRef();
  const showInputValue = () => {
    let inputName = name.value;
    let inputEmail = email.value;
    let concat = `Name = ${inputName} ___ Email = ${inputEmail}`;
    alert(concat);
  };

  //___ useRef() caching ___//
  let APIData = useRef(null);
  const fetchData = async () => {
    const response = await fetch("https://dummyjson.com/products/1");
    APIData.current = await response.json();
  };
  let data = useRef();
  const showData = () => {
    data.current.innerHTML = JSON.stringify(APIData.current);
  };

  return (
    <>
      <h3>UseRef</h3>

      {/* Change Dom text */}
      <p className="mb-3" ref={txt}>
        Main text
      </p>
      <button onClick={ChangeTxt}>Change text</button>
      <br />
      <br />

      {/* Add Css Class */}
      <p className="mb-3" ref={addClassDom}>
        Add Css Class
      </p>
      <button onClick={addClass}>Add class</button>
      <span className="mx-3"></span>
      <button onClick={removeClass}>Remove class</button>
      <br />
      <br />

      {/* Get input value using useRef() */}
      <input type="text" ref={(n) => (name = n)} placeholder="Name" />
      <input type="text" ref={(e) => (email = e)} placeholder="Email" />
      <br />
      <button className="my-3" onClick={showInputValue}>
        Show input value
      </button>

      {/* useRef() caching -> একই জিনিস বারবার use করতে হলে সেটা useRef() এর মধ্যে cach করে রেখে দিলে একই function বারবার execute হবে নাা */}
      <p ref={data}>Show Date</p>
      <button onClick={fetchData}>Cach data</button>
      <button onClick={showData}>Show Data</button>
    </>
  );
};

export default FunctionalUseRef;
