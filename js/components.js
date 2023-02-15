$(window).load(function () {
  if (location.pathname === "/index.html") {
    //arrow components for index
    fetch("/html/components/arrow.html")
      .then((response) => response.text())
      .then((data) => {
        document.querySelector("#arrowToTopIndex").innerHTML = data;

        let scrollToTop = document.getElementById("scroll_to_top");
        window.onscroll = function () {
          if (
            document.body.scrollTop > 20 ||
            document.documentElement.scrollTop > 20
          ) {
            scrollToTop.style.display = "block";
          } else {
            scrollToTop.style.display = "none";
          }
        };
      });
  } else {
    //arrow components
    fetch("components/arrow.html")
      .then((response) => response.text())
      .then((data) => {
        document.querySelector("#arrowToTop").innerHTML = data;

        let scrollToTop = document.getElementById("scroll_to_top");
        window.onscroll = function () {
          if (
            document.body.scrollTop > 20 ||
            document.documentElement.scrollTop > 20
          ) {
            scrollToTop.style.display = "block";
          } else {
            scrollToTop.style.display = "none";
          }
        };
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
  }
});
