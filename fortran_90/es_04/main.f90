program shapes
    implicit none

    integer :: len

    write (*, "(a)", advance="no") "Enter the length: "
    read *, len

    if(len < 0) then
        print "(/, a)", "Error: You must enter a positive value!"
    else
        print *, ""
        call rectangle(len)

        print *, ""
        call triangle_v1(len)

        print *, ""
        call triangle_v2(len)
    end if
end program shapes

subroutine rectangle(len)
    implicit none

    integer, intent(in) :: len
    integer :: i, j

    do i = 1, len, 1
        do j = 1, len, 1
            write (*, "(a)", advance="no") "*"
        end do

        print *, ""
    end do
end subroutine rectangle

subroutine triangle_v1(len)
    implicit none

    integer, intent(in) :: len
    integer :: i, j

    do i = 1, len, 1
        do j = 1, i, 1
            write (*, "(a)", advance="no") "*"
        end do

        print *, ""
    end do
end subroutine triangle_v1

subroutine triangle_v2(len)
    implicit none

    integer, intent(in) :: len
    integer :: i, j

    do i = 1, len, 1
        do j = 1, i - 1, 1
            write (*, "(a)", advance="no") " "
        end do

        do j = 1, len - i + 1, 1
            write (*, "(a)", advance="no") "*"
        end do

        print *, ""
    end do
end subroutine triangle_v2