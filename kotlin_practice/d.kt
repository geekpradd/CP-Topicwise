private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map{ it.toInt() }
fun main(){
	var t = readInt()
	while (t > 0){
		val n = readInt()
		var array = readInts()
		var steps = 0; var left_sum = 0; var right_sum = 0; var prev_left = 0; var prev_right = 0 
		var left_pointer = 0
		var right_pointer = n-1
		var left: Boolean = true
		while (left_pointer <= right_pointer){
			var sum = 0
			if (left){
				while (left_pointer <= right_pointer && sum <= prev_right){
					sum += array[left_pointer]
					left_pointer++
				}
				prev_left = sum
				left_sum += sum
				left = false
			}
			else {
				while (left_pointer <= right_pointer && sum <= prev_left){
					sum += array[right_pointer]
					right_pointer--
				}
				prev_right = sum 
				right_sum += sum
				left = true
			}
			steps++
		}
		println(steps.toString() + " " + left_sum.toString() + " " + right_sum.toString())
		t--
	}
}