import React, { useRef, useState, useEffect } from "react";
import "../assets/css/Loader.css";
import "../assets/js/Loader.js";

export default function ApiCalling() {
  // let apiData,
  //   view = useRef();

  // const getData = async () => {
  //   const response = await fetch("https://dummyjson.com/products/1");
  //   apiData = await response.json();
  //   console.log(apiData);
  // };
  // const showData = () => {
  //   view.innerText = JSON.stringify(apiData);
  // };

  // Api calling using useEffect

  let [apiData, setApiData] = useState();
  useEffect(() => {
    (async () => {
      let res = await fetch("https://dummyjson.com/products/1");
      setApiData(await res.json());
    })();
  }, []);

  return (
    <div className="demo">
      <h1>Call API</h1>

      {/* <button onClick={getData}>Get data</button>
      <p ref={(viewData) => (view = viewData)}></p>
      <button onClick={showData}>Show data</button> */}

      {/* Api calling using useEffect */}
      <p>{JSON.stringify(apiData)}</p>
    </div>
  );
}
