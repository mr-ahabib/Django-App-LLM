<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Upload</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f0f8ff;
            color: #333;
        }
        h1 {
            text-align: center;
            color: #0073e6;
        }
        input[type="file"] {
            display: block;
            margin: 20px auto;
            padding: 10px;
            border: 1px solid #0073e6;
            border-radius: 5px;
            background-color: #fff;
        }
        table {
            width: 90%;
            margin: 20px auto;
            border-collapse: collapse;
            background-color: #fff;
            border-radius: 5px;
            overflow: hidden;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        th, td {
            border: 1px solid #ddd;
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #0073e6;
            color: #fff;
        }
        td {
            background-color: #f9f9f9;
        }
        button {
            display: block;
            margin: 20px auto;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            background-color: #0073e6;
            color: #fff;
            cursor: pointer;
            font-size: 16px;
        }
        button:hover {
            background-color: #005bb5;
        }
        .popup {
            display: none;
            position: fixed;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
            background-color: white;
            padding: 20px;
            border: 1px solid #0073e6;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            z-index: 1001;
        }
        .overlay {
            display: none;
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(0, 0, 0, 0.5);
            z-index: 1000;
        }
        @media (max-width: 600px) {
            table, th, td {
                font-size: 14px;
            }
            button {
                width: 90%;
                font-size: 14px;
            }
            input[type="file"] {
                width: 90%;
                font-size: 14px;
            }
        }
    </style>
</head>
<body>
    <h1>File Upload</h1>
    <input type="file" id="fileInput" multiple>
    <table id="fileTable">
        <thead>
            <tr>
                <th>File Name</th>
                <th>File Size</th>
                <th>File Type</th>
                <th>Action</th>
            </tr>
        </thead>
        <tbody>
        </tbody>
    </table>
    <button id="assessButton">Assess</button>

    <div class="overlay" id="overlay"></div>
    <div class="popup" id="popup">
        <h2>Assess</h2>
        <label for="promptInput">Enter a value:</label>
        <input type="text" id="promptInput">
        <button id="submitPrompt">Submit</button>
        <button id="closePopup">Close</button>
    </div>

    <script>
        document.getElementById('fileInput').addEventListener('change', function(event) {
            const fileTableBody = document.getElementById('fileTable').getElementsByTagName('tbody')[0];
            fileTableBody.innerHTML = ''; // Clear existing rows

            Array.from(event.target.files).forEach(file => {
                const row = fileTableBody.insertRow();

                const cellName = row.insertCell(0);
                const cellSize = row.insertCell(1);
                const cellType = row.insertCell(2);
                const cellAction = row.insertCell(3);

                cellName.textContent = file.name;
                cellSize.textContent = (file.size / 1024).toFixed(2) + ' KB';
                cellType.textContent = file.type;

                const deleteButton = document.createElement('button');
                deleteButton.textContent = 'Delete';
                deleteButton.style.backgroundColor = '#ff4d4d';
                deleteButton.style.color = '#fff';
                deleteButton.style.border = 'none';
                deleteButton.style.padding = '5px 10px';
                deleteButton.style.borderRadius = '5px';
                deleteButton.style.cursor = 'pointer';
                deleteButton.addEventListener('click', function() {
                    fileTableBody.deleteRow(row.rowIndex - 1);
                });
                cellAction.appendChild(deleteButton);
            });
        });

        document.getElementById('assessButton').addEventListener('click', function() {
            document.getElementById('overlay').style.display = 'block';
            document.getElementById('popup').style.display = 'block';
        });

        document.getElementById('closePopup').addEventListener('click', function() {
            document.getElementById('overlay').style.display = 'none';
            document.getElementById('popup').style.display = 'none';
        });

        document.getElementById('submitPrompt').addEventListener('click', function() {
            const promptValue = document.getElementById('promptInput').value;
            alert('Prompt value submitted: ' + promptValue);
            document.getElementById('overlay').style.display = 'none';
            document.getElementById('popup').style.display = 'none';
        });
    </script>
</body>
</html>
