import turtle
def draw_square():
	sq_pen = turtle.Turtle()
	sq_pen.shape("turtle")
	sq_pen.color("pink")
	sq_pen.speed(4)
	i = 0
	while i < 4:
		sq_pen.forward(100)
		sq_pen.right(90)
		i += 1

def draw_circle():
	cir_pen = turtle.Turtle()
	cir_pen.shape("circle")
	cir_pen.color("blue")
	cir_pen.speed(4)
	cir_pen.circle(100)

def draw_triangle():
	tri_pen = turtle.Turtle()
	tri_pen.shape("classic")
	tri_pen.color("red")
	tri_pen.speed(5)
	
	tri_pen.forward(100)
	tri_pen.right(60)
	tri_pen.forward(100)
	tri_pen.right(150)
	tri_pen.forward(180)
		

def draw_shapes():
	carbet = turtle.getscreen()
	carbet.bgcolor("purple")
	draw_square()
	draw_circle()
	draw_triangle()
	carbet.exitonclick()
	
draw_shapes()