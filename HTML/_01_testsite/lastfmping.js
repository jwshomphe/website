document.addEventListener("DOMContentLoaded", function() {
    const LASTFM_USERNAME = "residentdrainer"; // Replace with your Last.fm username
    const API_KEY = "7c4e041855e3a5c5ca7543e594613aec"; // Get your API key from Last.fm

    const url = `https://ws.audioscrobbler.com/2.0/?method=user.getrecenttracks&user=${LASTFM_USERNAME}&api_key=${API_KEY}&format=json&limit=1`;

    fetch(url)
        .then(response => response.json())
        .then(data => {
            const track = data.recenttracks.track[0];
            const artist = track.artist["#text"];
            const song = track.name;
            const image = track.image[2]["#text"]; // Use a different index for different image sizes

            const html = `
                <div style="text-align: center;">
                    <img src="${image}" alt="Album Art" style="max-width: 700px;">
                    <p style="font-size: 1.2em;">Artist: ${artist}</p>
                    <p style="font-size: 1.2em;">Song: ${song}</p>
                </div>
            `;

            document.getElementById("last-listened").innerHTML = html;
        })
        .catch(error => {
            console.error("Error fetching data:", error);
            document.getElementById("last-listened").innerText = "Error fetching data";
        });
});
