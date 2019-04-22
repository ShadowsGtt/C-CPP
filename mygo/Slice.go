package main

import "fmt"


func main(){
	/* 定义一个切片 */
	var slice1 []int
	fmt.Print("This is slice\n")
	fmt.Print("empty slice:",slice1)
	fmt.Print("\n")

	slice1 = append(slice1 , 1)
	fmt.Printf("append '1': %v\n" , slice1)

	/* 使用make()函数去创建一个切片 */
	// 第一种方式  
	var slice2 = make([]int ,5)
	fmt.Printf("slice2: %+v\n" , slice2)
	slice2 =  append(slice2,10)
	slice22 := slice2[:]
	slice22 = append(slice22,11)
	fmt.Printf("slice22 after append slice22 :%v\n",slice22)
	fmt.Printf("slice2 after append slice22 :%v\n",slice2)

}
