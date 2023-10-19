import React from "react";

const RenderProps = ({ render }) => {
  return (
    <>
      <h1>{render(false)}</h1>
    </>
  );
};

export default RenderProps;
