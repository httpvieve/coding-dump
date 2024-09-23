// fetch ("https://pokeapi.co/api/v2/pokemon/mewtwo")
// .then (response => response.json())
// .then (data => console.log(data.name))
// .catch (error => console.error (error))

fetch_data();

async function fetch_data() {

    try {
        const name = document.getElementById("pokemon_name").value.toLowerCase();
        const response = await fetch (`https://pokeapi.co/api/v2/pokemon/${name}`);

        if (!response.ok) { throw new Error("Could not fetch pokemon info."); }

        const data = await response.json();
        const sprite = data.sprites.front_default;
        const img = document.getElementById("pokemon_sprite");
        img.src = sprite;
        img.style.display = "block";
        
    } catch (error) {

    console.error(error);
    }
}