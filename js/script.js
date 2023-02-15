const loader = document.querySelector(".loader"); //effet de chargement

window.addEventListener("load", () => {
  loader.classList.add("fondu-out"); //effet fin de chargement "sur le css"
  setTimeout(() => {}, 500);
});

const accordionItemHeaders = document.querySelectorAll(
  ".accordion-item-header"
);

accordionItemHeaders.forEach((accordionItemHeader) => {
  accordionItemHeader.addEventListener("click", (event) => {
    // Programme javascript ANIMATION DU MENU DEROULANT
    //pour avoir seulement un onglet qui defile , le maximum

    // const currentlyActiveAccordionItemHeader = document.querySelector(".accordion-item-header.active");
    // if(currentlyActiveAccordionItemHeader && currentlyActiveAccordionItemHeader!==accordionItemHeader) {
    //   currentlyActiveAccordionItemHeader.classList.toggle("active");
    //  currentlyActiveAccordionItemHeader.nextElementSibling.style.maxHeight = 0;
    //   }
    //pour avoir seulement un onglet qui defile , le maximum

    accordionItemHeader.classList.toggle("active");
    const accordionItemBody = accordionItemHeader.nextElementSibling;
    if (accordionItemHeader.classList.contains("active")) {
      accordionItemBody.style.maxHeight = accordionItemBody.scrollHeight + "px";
    } else {
      accordionItemBody.style.maxHeight = 0;
    }
  });
});
