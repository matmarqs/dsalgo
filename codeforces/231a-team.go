package main

import (
    "fmt"
)

func isSure(a int, b int, c int) int {
    return a & b | b & c | c & a
}

func main() {
    var n int
    fmt.Scanln(&n)
    var i int
    var numProblems int = 0
    for i = 0; i < n; i++ {
        var a, b, c int
        fmt.Scan(&a, &b, &c)
        numProblems += isSure(a,b,c)
    }
    fmt.Println(numProblems)
}
