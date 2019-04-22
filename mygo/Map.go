package  main

import "fmt"

func main(){

	/* map 的定义 */
	var map1  map[string]string
	fmt.Print(map1,"\n")

	map2 := map[string]string{"name":"shadowgao" , "company":"tencent"}
	fmt.Print(map2)
	fmt.Println("")

	map3 := make(map[string]string)
	fmt.Print(map3)
	fmt.Println("")


	map2["school"] = "university"
	map2["sex"] = "man"

	/* 使用for 得到map的key value */
	for k , v := range map2{
		fmt.Println(k,"->",v)
	}

	/* map 的删除 */
	fmt.Println("删除前:")
	fmt.Println(map2)

	fmt.Println("删除sex后")
	delete(map2,"sex")
	fmt.Println(map2)

	/* 确定某元素是否在map中 */
	{
		v , ok := map2["sex"]
		if(ok){
			fmt.Println("value of key 'sex' is :",v)
		}else{
			fmt.Println("key 'sex' not exist")
		}
	}

	{
		v , ok := map2["school"]
		if(ok){
			fmt.Println("value of key 'school' is :",v)
		}else{
			fmt.Println("key 'school' not exist")
		}
	}
}
