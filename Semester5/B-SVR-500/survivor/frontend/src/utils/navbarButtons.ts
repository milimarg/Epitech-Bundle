export const navbarButtons = [
  { text: "Home", route: "/home", permissions: ["ADMIN", "COACH"] },
  { text: "Astro-match", route: "/astro-match", permissions: ["ADMIN", "COACH"] },
  { text: "Wardrobe", route: "/wardrobe", permissions: ["ADMIN", "COACH"] },
  { text: "Coaches", route: "/coaches", permissions: ["ADMIN"] },
  { text: "Customers", route: "/customers", permissions: ["ADMIN", "COACH"] },
  { text: "Tips", route: "/tips", permissions: ["ADMIN", "COACH"] },
  { text: "Events", route: "/events", permissions: ["ADMIN", "COACH", "CUSTOMER"] }
];
