import React, { useReducer } from "react";

const initialValue = 0;

const reducer = (state, action) => {
  switch (action) {
    case "increment":
      return state + 1;
      break;
    case "decrement":
      return state - 1;
      break;
    default:
      return state;
  }
};

const UseReducer = () => {
  const [count, dispatch] = useReducer(reducer, initialValue);
  return (
    <>
      <h3>Use Reducer</h3>

      <p className="mb-3">Use Reducer count : {count}</p>
      <button onClick={() => dispatch("increment")}>Increment</button>
      <span className="mx-3"></span>
      <button onClick={() => dispatch("decrement")}>Decrement</button>

      <br />
    </>
  );
};

export default UseReducer;
