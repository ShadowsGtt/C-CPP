package main

import "fmt"

type MySQL struct {
	 str string
	 te  int
}

func (mysql *MySQL )printMySQL()()  {
	fmt.Println(mysql.str,mysql.te)
}

func main()  {
	var mysql MySQL = MySQL{
		str: "hello",
		te:  1,
	}
	mysql.printMySQL()
}
