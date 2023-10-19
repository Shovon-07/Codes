import React, { useState } from "react";

let runCount;

function FunctionalUseState() {
  const [name, setName] = useState("____");
  let [count, setCount] = useState(0);
  let [autoCount, setAutoCount] = useState(0);

  // Change value
  const ChangeName = (e) => {
    const inputValue = e.target.value;
    if (inputValue === "") {
      setName("____");
    } else {
      setName(inputValue);
    }
  };

  // Counter
  const Counter = () => {
    setCount(count + 1);
  };

  // Autometic Counter
  const StartCount = () => {
    runCount = setInterval(() => {
      setAutoCount((autoCount += 1));
    }, 100);
  };
  const PauseCount = () => {
    clearInterval(runCount);
  };
  const ResetCount = () => {
    clearInterval(runCount);
    setAutoCount(0);
  };

  return (
    <>
      <h3>UseState in Functional component</h3>

      {/* Change value */}
      <input type="text" placeholder="Enter your name" onChange={ChangeName} />
      <h3>My Name is {name} </h3>
      <br />

      {/* Counter */}
      <h3>Count : {count} </h3>
      <button onClick={Counter}>Counter</button>
      <br />
      <br />

      {/* Autometic Counter */}
      <h3>Auto count : {autoCount}</h3>
      <button onClick={StartCount}>Start</button>
      <span className="mx-4"></span>
      <button onClick={PauseCount}>Pause</button>
      <span className="mx-4"></span>
      <button onClick={ResetCount}>Reset</button>

      <br />
      <br />
    </>
  );
}
export default FunctionalUseState;
