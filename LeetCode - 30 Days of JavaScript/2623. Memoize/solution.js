/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
  const memo = {};
  return function(...args) {
    const key = JSON.stringify(args);
    console.log(key);

    if(key in memo)
      return memo[key];

    const result = fn.apply(this, args);
    memo[key] = result;

    return result;
  }
}


/** 
* let callCount = 0;
* const memoizedFn = memoize(function (a, b) {
*	 callCount += 1;
*   return a + b;
* })
* memoizedFn(2, 3) // 5
* memoizedFn(2, 3) // 5
* console.log(callCount) // 1 
*/