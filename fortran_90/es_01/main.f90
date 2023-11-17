program int_sum
    implicit none

    integer :: num1, num2

    print "(a)", "Enter two integers:"
    read *, num1, num2

    print "(i0, a, i0, a, i0)", num1, " + ", num2, " = ", (num1 + num2)
end program int_sum