package main

import "fmt"

func main(){

	a := []int {10,11,12}
	for _, val := range a{
		fmt.Print(val," ")
	}
	fmt.Println("")

	for i , val := range a {
		fmt.Printf("a[%d] = %d\n",i,val)
	}

	mp := map[string]string {"name":"shadowgao" , "company":"tencent"}
	for k ,v := range mp {
		fmt.Print(k,"->",v)
		fmt.Println("")
	}
}
