import React, { useEffect, useState } from "react";

const FunctionalUseEffect = () => {
  const [count, setCount] = useState(0);
  const [date, setDate] = useState(new Date());

  const Counter = () => {
    setCount(count + 1);
  };

  // Titele counter update
  useEffect(() => {
    // document.title = `Clicked ${count} times`;
  }, [count]);

  const tick = () => {
    setDate(new Date());
  };

  // Clock update
  let runClock;
  useEffect(() => {
    // runClock = setInterval(tick, 1000);

    // When component unmounted, then clock was stop
    return () => {
      // console.log("Component unmounted");
      clearInterval(runClock);
    };
  });

  return (
    <>
      <br />
      <h3>UseEffect</h3>

      <h3>Time : {date.toLocaleTimeString()}</h3>

      <p>{count}</p>
      <button onClick={Counter}>Click</button>
    </>
  );
};

export default FunctionalUseEffect;
