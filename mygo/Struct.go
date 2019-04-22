
package main

import "fmt"

type sct1 struct{
	name string
	age int
}
type sct2 struct{
	name string
	age int
}

func main(){
	var st1 = sct1{"hello",1}
	st2 := sct2{"hi",2}
	fmt.Println(st1)
	fmt.Println(st2)
	fmt.Println("")
}
