const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Enter two numbers: ", (input) => {
  let [a, b] = input.split(" ").map(Number);
  console.log(lcm(a, b));
  rl.close();
});

function max2prod(n, L) {
  let max1 = 0;
  let max2 = 0;
  for (let i = 0; i < n; i++) {
    if (L[i] > max1) {
      max2 = max1;
      max1 = L[i];
    }
    else if (L[i] > max2)
      max2 = L[i]
  }
  return max1 * max2;
}
