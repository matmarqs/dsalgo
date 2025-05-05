package main

import "fmt"

func main() {
    var w int
    fmt.Scan(&w)
    if w >= 4 && w % 2 == 0 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
