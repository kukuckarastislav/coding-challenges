/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
  return function(x) {
    if(functions.length == 0) 
      return x;
    let r = 0;
    for(let f of functions.reverse()){
      r = f(x);
      x = r;
    }
    return r;
  }
};

/**
* const fn = compose([x => x + 1, x => 2 * x])
* fn(4) // 9
*/