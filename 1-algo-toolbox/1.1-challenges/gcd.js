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

function gcd(a, b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

function lcm(a, b) {
  return (a / gcd(a, b)) * b;
}
