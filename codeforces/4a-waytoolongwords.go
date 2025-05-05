package main

import (
    "fmt"
)

func abbreviate(str string) string {
    var n int = len(str)
    if n > 10 {
        return fmt.Sprintf("%c%d%c", str[0], len(str)-2, str[n-1])
    } else {
        return str
    }
}

func main() {
    var n int
    var i int
    fmt.Scanln(&n)
    var str string;
    for i = 0; i < n; i++ {
        fmt.Scanln(&str)
        fmt.Println(abbreviate(str))
    }
}
