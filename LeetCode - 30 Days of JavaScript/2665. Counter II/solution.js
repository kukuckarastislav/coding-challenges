/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
  let start = init;
  return {
      increment: () => {return ++start;},
      decrement: () => {return --start;},
      reset: () => {start = init; return start;}
  }
};

/**
* const counter = createCounter(5)
* counter.increment(); // 6
* counter.reset(); // 5
* counter.decrement(); // 4
*/