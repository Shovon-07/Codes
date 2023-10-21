import React, { useEffect, useState } from "react";

const ClockInFunctionalComponent = () => {
  const [time, setTime] = useState(new Date());

  const runClock = () => {
    setTime(new Date());
  };

  useEffect(() => {
    // setInterval(runClock, 1000);
  }, []);

  return (
    <>
      <h2 className="text-light">{time.toLocaleTimeString()}</h2>
    </>
  );
};

export default ClockInFunctionalComponent;
