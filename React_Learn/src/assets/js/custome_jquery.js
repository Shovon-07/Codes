//___ Owl-carousel ___//
$('.carousel-1').owlCarousel({
    loop:true,
    nav:false,
    margin:0,
    autoplay:true,
    autoplayTimeout:4000,
    autoplayHoverPause:true,
    responsive:{
        0:{
            items:1
        },
        600:{
            items:1
        },
        1000:{
            items:1
        }
    }
})

//________________ Window scroll start ________________//
$(window).scroll(()=> {
    if(this.scrollY > 50) {
        $('.header').addClass('active');
    } else {
        $('.header').removeClass('active');
    }
})
//________________ Window scroll end ________________//