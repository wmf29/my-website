<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // تنظيف المدخلات
    $data = [
        'firstName' => htmlspecialchars($_POST['firstName']),
        'lastName' => htmlspecialchars($_POST['lastName']),
        'screenName' => htmlspecialchars($_POST['screenName']),
        'dob' => $_POST['year'] . '-' . $_POST['month'] . '-' . $_POST['day'],
        'gender' => htmlspecialchars($_POST['gender']),
        'country' => htmlspecialchars($_POST['country']),
        'email' => filter_var($_POST['email'], FILTER_SANITIZE_EMAIL),
        'phone' => htmlspecialchars($_POST['phone']),
    ];
?>
<!DOCTYPE html>
<html>
<head>
    <title>Registration Result</title>
    <style>
        /* نفس التنسيقات السابقة */
    </style>
</head>
<body>
    <div class="container">
        <h2>Registration Successful!</h2>
        <div class="result">
            <p>First Name: <?= $data['firstName'] ?></p>
            <p>Last Name: <?= $data['lastName'] ?></p>
            <p>Screen Name: <?= $data['screenName'] ?></p>
            <p>Date of Birth: <?= $data['dob'] ?></p>
            <p>Gender: <?= $data['gender'] ?></p>
            <p>Country: <?= $data['country'] ?></p>
            <p>Email: <?= $data['email'] ?></p>
            <p>Phone: <?= $data['phone'] ?></p>
        </div>
    </div>
</body>
</html>
<?php
} else {
    header("Location: form.html");
    exit();
}
?>
