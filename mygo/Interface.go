package main



import "fmt"

/*
* 	interface中的方法名和实现interface函数的结构中的变量名不可以相同
*  	Eg：Women结构体中有变量叫name ,那interface中的方法名就不可以叫name()
*/


type InterFace interface{
	get_name()
	get_age()
}


/* Women 相关函数 */

type  Women struct {
	name string
	age int
}

func (people Women) get_name() {
	fmt.Println("This is Women name")
	fmt.Println("name :" , people.name)
}
func (people Women) get_age() {
	fmt.Println("This is Women age")
	fmt.Println("age :" , people.age)
}


/* man 相关函数 */

type Man struct {
	name string
	age int
}

func (people Man) get_name(){
	fmt.Println("This is man name")
	fmt.Println("name :" , people.name)
}

func (people Man) get_age(){
	fmt.Println("This is man age")
	fmt.Println("age :" , people.age)
}
func main(){
	var people InterFace

	man := Man{"man",21}
	people = man
	people.get_name()
	people.get_age()

	var women Women
	women.name = "women"
	women.age = 21
	people = women
	people.get_name()
	people.get_age()

}
