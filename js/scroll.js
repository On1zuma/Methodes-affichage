$(window).load(function () {
  jQuery(function () {
    $("#scroll_to_top").css("transition", "visibility 0s, opacity 0.5s linear");
    $("#scroll_to_top").css("visibility", "hidden");
    $("#scroll_to_top").css("opacity", "0");
    $(function () {
      $(window).scroll(function () {
        if ($(this).scrollTop() > 200) {
          $("#scroll_to_top").css("right", "17px");
          $("#scroll_to_top").css("visibility", "visible");
          $("#scroll_to_top").css("opacity", "0.8");
          $("#scroll_to_top").css(
            "transition",
            "visibility 0s, opacity 0.5s linear"
          );
        } else {
          //  $('#scroll_to_top').css('display','none');
          $("#scroll_to_top").css(
            "transition",
            "visibility 0s, opacity 0.5s linear"
          );
          $("#scroll_to_top").css("visibility", "hidden");
          $("#scroll_to_top").css("opacity", "0");
        }
      });
    });
  });

  //arrow components
  fetch("components/arrow.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("#arrowToTop").innerHTML = data;
    });

  //arrow components for index
  fetch("/html/components/arrow.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("#arrowToTopIndex").innerHTML = data;
    });

  // footer components
  fetch("components/footer.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("#footerContainer").innerHTML = data;
    });

  //nav components
  fetch("components/nav.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("#appnavbar").innerHTML = data;
    });
});
