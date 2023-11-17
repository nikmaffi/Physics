program stars
    implicit none

    integer :: num_stars, counter

    write (*, "(a)", advance="no") "Enter the number of stars: "
    read *, num_stars

    if(num_stars < 0) then
        print "(/, a)", "Error: The number of stars must be positive!"
    else
        do counter = 1, num_stars, 1
            write (*, "(a)", advance="no") "*"
        end do

        print *, ""
    end if
end program stars