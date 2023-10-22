import React, { useRef } from "react";
import { useState } from "react";

const Hook = () => {
  //___ Dom Manupulation ___//
  let getElement = useRef();
  const changeDom = () => {
    getElement.current.innerHTML =
      "Change dom element text using hook(useRef())";
    getElement.current.style.color = "red";
  };

  //___ Add Css Class ___//
  let addCssDom = useRef();
  const addCss = () => {
    addCssDom.current.classList.add("addCssDom");
  };
  const removeCss = () => {
    addCssDom.current.classList.remove("addCssDom");
  };

  //___ Get input value ___//
  let fName,
    lName = useRef();
  const Show_input_value = () => {
    let firstName = fName.value;
    let lastName = lName.value;
    alert(firstName.concat(" ", lastName));
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

  //___ useState ___//
  const [number, useStateNum] = useState(1);

  //___ UseState Object ___//
  let [useStateObj, changeUseStateObj] = useState({
    name: "shovon",
    age: 20,
    gender: "male",
  });
  changeUseStateObj = () => {
    useStateObj.name = "Jubair";
  };

  return (
    <>
      <h1 className="text-danger">React Hook start</h1>
      {/* useref (It use for dom manupulation) */}
      <p ref={getElement}>Hook</p>
      <button onClick={changeDom}>Change Dom Text</button>

      <br />
      <br />

      {/* How to add/remove css class */}
      <p ref={addCssDom}>Add Css class</p>
      <button onClick={addCss}>Add Css</button>
      <button onClick={removeCss}>Remove Css</button>

      <br />
      <br />

      {/* Get input value using useRef() */}
      <input ref={(f) => (fName = f)} type="text" placeholder="First name" />
      <br />
      <input ref={(l) => (lName = l)} type="text" placeholder="Last name" />
      <br />
      <button onClick={Show_input_value}>Show input value</button>

      <br />
      <br />

      {/* useRef() caching -> একই জিনিস বারবার use করতে হলে সেটা useRef() এর মধ্যে cach করে রেখে দিলে একই function বারবার execute হবে নাা */}
      <p ref={data}></p>
      <button onClick={fetchData}>Cach data</button>
      <button onClick={showData}>Show Data</button>

      <br />
      <br />

      {/* useState() */}
      <p>Use State number = {number}</p>
      <button onClick={() => useStateNum(number + 1)}>Use State</button>

      <br />
      <br />

      {/* useState() in object */}
      <p>{useStateObj.name}</p>
      <button onClick={changeUseStateObj}>Change useState Object</button>

      <br />
      <h1 className="text-danger">React Hook end</h1>

      <br />
      <br />
    </>
  );
};

export default Hook;
