package main

import "fmt"
func main(){

	mp := map[string]interface{}{
		"name":"gtt",
		"school":"know",
	}
	if v,OK := mp["name"];OK{
		fmt.Println("name exist : v=%v",v)
	}
	if v,OK := mp["age"];OK{
		fmt.Println("age exist : v=%v",v)
	}

	var ok bool = false
	if ok{

	} else if ok == false{

	}
}
