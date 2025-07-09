# To run this file in terminal
#  .\log_progress.ps1


# Set root and log file path
$root = "C:\A2Z_Striver_Solution"
$logPath = Join-Path $root "progress_log.md"

# Initialize counters
$totalCpp = 0
$totalExe = 0

# Reset log file
Set-Content $logPath "#  Striver A2Z Progress Log`n"

# Count totals first
$totalCpp = (Get-ChildItem -Path $root -Recurse -Filter "*.cpp").Count
$totalExe = (Get-ChildItem -Path $root -Recurse -Filter "*.exe").Count

# Write total summary
Add-Content $logPath "`n**Total Solved Problems (CPP):** $totalCpp"
Add-Content $logPath "`n**Total Compiled Files (EXE):** $totalExe`n"
Add-Content $logPath "`n---`n"

# Traverse each Week folder
Get-ChildItem -Path $root -Directory | Where-Object { $_.Name -like "Week_*" } | ForEach-Object {
    $week = $_.Name
    Add-Content $logPath "## $week"

    # Traverse Day folders inside each Week
    Get-ChildItem -Path $_.FullName -Directory | Where-Object { $_.Name -like "Day_*" } | ForEach-Object {
        $day = $_.Name
        $cppFiles = Get-ChildItem -Path $_.FullName -Filter "*.cpp"
        $exeFiles = Get-ChildItem -Path $_.FullName -Filter "*.exe"

        if ($cppFiles.Count -gt 0) {
            Add-Content $logPath "### $day - $($cppFiles.Count) Problem(s), $($exeFiles.Count) Executables"
            foreach ($file in $cppFiles) {
                Add-Content $logPath "- $($file.BaseName)"
            }
        } else {
            Add-Content $logPath "### $day -  No problems solved."
        }

        Add-Content $logPath ""
    }

    Add-Content $logPath "`n---`n"
}

Write-Output "Progress log created at: $logPath"
