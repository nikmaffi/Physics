program modulus
    implicit none

    integer :: num1, num2

    print "(a)", "Enter two integers:"
    read *, num1, num2

    if(num2 == 0) then
        print "(/, a)", "Error: cannot divide by zero!"
    else
        if(mod(num1, num2) == 0) then
            print "(/, i0, a, i0)", num1, " is a multiple of ", num2
        else
            print "(/, i0, a, i0)", num1, " is NOT a multiple of ", num2
        end if
    end if
end program modulus