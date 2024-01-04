//_____ Customize theme start _____//
let toggle_theme = document.querySelector(".toggle-theme");
let theme_icon = document.querySelector(".toggle-theme .fa-moon");
let setThemeValue;

// Change theme
const lightTheme = () => {
  document.body.classList.add("light");
  theme_icon.classList.replace("fa-moon", "fa-sun");
  setThemeValue = localStorage.setItem("Theme", 1);
};
const darkTheme = () => {
  document.body.classList.remove("light");
  theme_icon.classList.replace("fa-sun", "fa-moon");
  setThemeValue = localStorage.setItem("Theme", 2);
};

toggle_theme.addEventListener("click", () => {
  if (!document.body.classList.contains("light")) {
    lightTheme();
  } else {
    darkTheme();
  }
});

// Stop refresh theme
window.addEventListener("DOMContentLoaded", () => {
  let getThemeValue = localStorage.getItem("Theme");
  if (getThemeValue == 1) {
    lightTheme();
  } else if (getThemeValue == 2) {
    darkTheme();
  }
});
//_____ Customize theme end _____//

//_____ Nav bar background change when Window was scrolled start _____//
const header = document.querySelector("header");
window.addEventListener("scroll", () => {
  let pageHeight = window.scrollY;
  header.classList.toggle("scrolled", pageHeight > 10);
});
//_____ Nav bar background change when Window was scrolled end _____//

//___ Contact alert start ___//
let showAlert = document.querySelector("#showAlert");
let popup = document.querySelector(".popup");
let popupBtn = document.querySelector(".popup button");

showAlert.addEventListener("click", () => {
  popup.classList.add("active");
});
popupBtn.addEventListener("click", () => {
  popup.classList.remove("active");
});
//___ Contact alert end ___//


let top_scroller = document.querySelector(".top_scroller");
document.addEventListener("scroll", ()=> {
    let scroll = window.scrollY;
    if(scroll>100) {
        top_scroller.classList.add('fa_solid_viewer');
    }
    else {
        top_scroller.classList.remove('fa_solid_viewer');
    }
})


//_____ one click go to top btn _____//
 let top_scroller = document.querySelector(".top_scroller");
 top_scroller.addEventListener("click", () => {
   window.scrollTo({ top: 0, behavior: "smooth" });
 });


//_____ Password show & hide using javascript _____//
let eye = document.querySelector("#eye");
eye.addEventListener('click', () => {
    let pass_input = document.querySelector("#pass_input");
    let eye_open = document.querySelector("#eye_open");
    let eye_cls = document.querySelector("#eye_cls");

    if (pass_input.type === 'password') {
        pass_input.type = 'text';
        eye_cls.style.display = 'block';
        eye_open.style.display = 'none';
    } else {
        pass_input.type = 'password';
        eye_open.style.display = 'block';
        eye_cls.style.display = 'none';
    }
})


//_____ Password show & hide using jquery _____//

$('#eye_open').click(function () { 
    if($('#pass_input').attr('type', 'password')) {
        $('#pass_input').attr('type', 'text');
        $('#eye_open').hide();
        $('#eye_cls').show();
    }
});
$('#eye_cls').click(function () { 
    if($('#pass_input').attr('type', 'text')) {
        $('#pass_input').attr('type', 'password');
        $('#eye_open').show();
        $('#eye_cls').hide();
    }
});


//________ side bar dropdown ________//

const allDropdown = document.querySelectorAll('.sidebar .side-dropdown');
allDropdown.forEach(item=> {
    const a = item.parentElement.querySelector('a:first-child');
    a.addEventListener('click', function(e) {
        e.preventDefault();
        this.classList.toggle('active');
        item.classList.toggle('show');
    })
})


//________ profile dropdown start ________//

const profile = document.querySelector('nav .profile');
const imgProfile = profile.querySelector('img');
const dropdownProfile = profile.querySelector('.profile-link');

imgProfile.addEventListener('click', function() {
    dropdownProfile.classList.toggle('show');
})
//________ profile dropdown end ________//

//________ Set Interval start ________//
 let number = document.querySelector("#number");
 let counter = 0;

 setInterval(() => {
     if (counter == 65) {
         clearInterval();
     }
     else {
         counter += 1;
         number.innerHTML = "HTML" + "<br>" + counter + "%";
         number.style.textAlign = "center";
     }
 }, 30)
 //________ Set Interval end ________//

//_____ How to add active class _____//
 let menus = document.querySelectorAll("#menu");
 for (let i=0; i<menus.length; i++) {
     menus[i].addEventListener("click", function() {
         let active = document.getElementsByClassName("active");
         active[0].className = active[0].className.replace("active", " ");
         this.className += "active";
     })
}

//___ Go to top start ___//

var offset = 300;
var duration = 100;
jQuery(window).on("scroll", function () {
  if (jQuery(this).scrollTop() > offset) {
    jQuery(".scroll-to-top").addClass("active-arrow");
  } else {
    jQuery(".scroll-to-top").removeClass("active-arrow");
  }
});
jQuery(".scroll-to-top").on("click", function (event) {
  event.preventDefault();
  jQuery("html, body").animate({ scrollTop: 0 }, duration);
  return false;
});

//___ Go to top end ___//

//_____ Window scroll section animation _____//

window.addEventListener("scroll", reveal);

function reveal() {
  var reveal = document.querySelectorAll(
    "#right_slide_box, #scale_box, #left_slide_box"
  );

  for (var i = 0; i < reveal.length; i++) {
    var window_height = window.innerHeight;
    var reveal_top = reveal[i].getBoundingClientRect().top;
    var reveal_point = 50;

    if (reveal_top < window_height - reveal_point) {
      reveal[i].classList.add("reveal");
    } else {
      reveal[i].classList.remove("reveal");
    }
  }
}

/************* My Full name section *************/
/*
document.querySelector("#see_my_full_name").addEventListener("click", () => {
  document.querySelector("#my_full_name").style.visibility = "visible";

  let img_change = document.querySelector("#img_change");
  img_change.src = "web-page.jpg";
});
*/
/************* Your Full name section *************/
/*
document.querySelector("#your_full_Name").addEventListener("click", () => {
  let f_name = document.querySelector("#f_name").value;
  let l_name = document.querySelector("#l_name").value;
  let full_name_output = document.querySelector("#full_name_output");

  let total_name = "Name =   " + f_name + " " + l_name;
  full_name_output.value = total_name;
});
*/
/************* Calculator section *************/
/*
document.querySelector("#sum_res_btn").addEventListener("click", () => {
  let f_number = document.querySelector("#f_number");
  let l_number = document.querySelector("#l_number");
  let sum_output = document.querySelector("#sum_output");

  let total_sum =
    "Sum =    " + (parseInt(f_number.value) + parseInt(l_number.value));

  sum_output.value = total_sum;
});
*/
/************* Temperature Calculator section *************/
/*
document.querySelector("#tempa_res_btn").addEventListener("click", () => {
  let f_tempa = document.querySelector("#f_tempa");
  let tempa_output = document.querySelector("#tempa_output");

  total_tempa = "Celsius =    " + (5 / 9) * (parseInt(f_tempa.value) - 32);

  tempa_output.value = total_tempa;
});
*/
/************* How many charecter section *************/
/*
document
  .querySelector("#how_many_char_res_btn")
  .addEventListener("click", () => {
    let how_many_char = document.querySelector("#how_many_char");
    let tempa_output = document.querySelector("#how_many_char_output");

    total_char = "Total charecter =    " + how_many_char.value.length;

    tempa_output.value = total_char;
  });
*/
/************* Exam result section *************/
/*
document.querySelector("#exam_res_btn").addEventListener("click", () => {
  let exam_mark = document.querySelector("#exam_mark").value;
  let exam_point_output = document.querySelector("#exam_point_output");
  let exam_grade_output = document.querySelector("#exam_grade_output");
  let achive_txt = "You Achive = ";

  if (exam_mark > 100 || exam_mark < 0) {
    exam_point_output.value = "Invalid input";
    exam_grade_output.value = "Invalid input";
  } else if (exam_mark >= 80) {
    exam_point_output.value = achive_txt + "4.00";
    exam_grade_output.value = achive_txt + "A+";
  } else if (exam_mark >= 75) {
    exam_point_output.value = achive_txt + "3.75";
    exam_grade_output.value = achive_txt + "A";
  } else if (exam_mark >= 70) {
    exam_point_output.value = achive_txt + "3.50";
    exam_grade_output.value = achive_txt + "A-";
  } else if (exam_mark >= 65) {
    exam_point_output.value = achive_txt + "3.25";
    exam_grade_output.value = achive_txt + "B+";
  } else if (exam_mark >= 60) {
    exam_point_output.value = achive_txt + "3.00";
    exam_grade_output.value = achive_txt + "B";
  } else if (exam_mark >= 55) {
    exam_point_output.value = achive_txt + "2.75";
    exam_grade_output.value = achive_txt + "B-";
  } else if (exam_mark >= 50) {
    exam_point_output.value = achive_txt + "2.50";
    exam_grade_output.value = achive_txt + "C+";
  } else if (exam_mark >= 45) {
    exam_point_output.value = achive_txt + "2.25";
    exam_grade_output.value = achive_txt + "C";
  } else if (exam_mark >= 40) {
    exam_point_output.value = achive_txt + "2.00";
    exam_grade_output.value = achive_txt + "D";
  } else {
    exam_point_output.value = achive_txt + "0.00";
    exam_grade_output.value = "You are FAIL";
  }
});
*/
