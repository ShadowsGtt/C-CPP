package main

import "fmt"

func interface2String(inter interface{}) {
	switch inter.(type) {
	case string:
		if res := inter.(string); res != "" {
			fmt.Println("ok == true,string", inter.(string))
		} else {
			fmt.Println("ok == false")
		}
		break
	case int:
		fmt.Println("int", inter.(int))
		break
	case float64:
		fmt.Println("float64", inter.(float64))
		break
	}
}

func main() {

	interface2String("jack")

}
