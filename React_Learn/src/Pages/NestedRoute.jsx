import React from "react";

/* Routin */
import { Outlet } from "react-router-dom";

const NestedRoute = () => {
  return (
    <>
      <h1>This is NestedRoute</h1>
      <Outlet />
    </>
  );
};

export default NestedRoute;
